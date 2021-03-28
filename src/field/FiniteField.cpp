#include "FiniteField.h"
#include "IntegersModuloNField.h"

FiniteField::FiniteField() {}

FiniteField::FiniteField(const FiniteField &finiteField) {
    copyFiniteField(finiteField);
}

FiniteField &FiniteField::operator=(const FiniteField &finiteField) {
    deallocateSpace();
    copyFiniteField(finiteField);
    return *this;
}

int FiniteField::getSize() const {
    return m_size;
}

bool FiniteField::operator==(const FiniteField &finiteField) const {
    if (m_size != finiteField.m_size) {
        return false;
    }
    for (int i = 0; i < m_size; i++) {
        if (m_set[i] != finiteField.m_set[i]) {
            return false;
        }
    }
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            if (m_additionMappings[i][j] != finiteField.m_additionMappings[i][j]) {
                return false;
            }
            if (m_multiplicationMappings[i][j] != finiteField.m_multiplicationMappings[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool FiniteField::operator!=(const FiniteField &finiteField) const {
    return !(finiteField == *this);
}

string FiniteField::getName() const {
    return "Finite field (n=" + to_string(m_size) + ")";
}

double *FiniteField::getSet() const {
    return m_set;
}

double **FiniteField::getAdditionMappings() const {
    return m_additionMappings;
}

double **FiniteField::getMultiplicationMappings() const {
    return m_multiplicationMappings;
}

int FiniteField::getIndexInSet(double value) const {
    for (int i = 0; i < m_size; i++) {
        if (abs(m_set[i] - value) <= 1e-6) {
            return i;
        }
    }
    return -1;
}

bool FiniteField::isIsomorphicTo(BaseMathField *field) const {
    auto *integersModuloNField = dynamic_cast<IntegersModuloNField *>(field);
    if (integersModuloNField and m_size == integersModuloNField->getModulus()) {
        return true;
    }

    auto *finiteField = dynamic_cast<FiniteField *>(field);
    if (finiteField and m_size == finiteField->getSize()) {
        return true;
    }

    return false;
}

void FiniteField::promptCreation() {
    promptSet();
    promptAdditionMapping();
    promptMultiplicationMapping();
    assertIsField();
}

FiniteFieldNumber FiniteField::createNumber() {
    return FiniteFieldNumber(this);
}

FiniteField::~FiniteField() {
    deallocateSpace();
}

void FiniteField::copyFiniteField(const FiniteField &finiteField) {
    m_size = finiteField.getSize();

    m_set = new double[m_size];
    for (int i = 0; i < m_size; i++) {
        m_set[i] = finiteField.m_set[i];
    }

    m_additionMappings = new double *[m_size];
    for (int i = 0; i < m_size; i++) {
        m_additionMappings[i] = new double[m_size];
        for (int j = 0; j < m_size; j++) {
            m_additionMappings[i][j] = finiteField.m_additionMappings[i][j];
        }
    }

    m_multiplicationMappings = new double *[m_size];
    for (int i = 0; i < m_size; i++) {
        m_multiplicationMappings[i] = new double[m_size];
        for (int j = 0; j < m_size; j++) {
            m_multiplicationMappings[i][j] = finiteField.m_multiplicationMappings[i][j];
        }
    }
}

void FiniteField::deallocateSpace() {
    delete[] m_set;
    for (int i = 0; i < m_size; i++) {
        delete[] m_additionMappings[i];
        delete[] m_multiplicationMappings[i];
    }
    delete[] m_additionMappings;
    delete[] m_multiplicationMappings;
}


void FiniteField::promptSet() {
    cout << "\n";
    int setSize;
    while (true) {
        cout << "Enter the set size (>=2): ";
        if (cin >> setSize and setSize >= 2) {
            break;
        } else {
            cout << "\n[!] Please enter a valid set size.\n\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }

    if (not MathUtils::isPrime(setSize)) {
        cout << "\n[!] A finite field must have a prime number of elements.";
        throw NotAFieldException();
    }

    m_size = setSize;
    m_set = new double[setSize];

    cout << "Enther the " << m_size << " set elements: ";

    bool hasZero = false, hasOne = false;
    for (int i = 0; i < m_size; i++) {
        cin >> m_set[i];

        if (m_set[i] == 0) {
            hasZero = true;
        } else if (m_set[i] == 1) {
            hasOne = true;
        }
    }

    // Additional checks
    sort(m_set, m_set + m_size);
    for (int i = 1; i < m_size; i++) {
        if (m_set[i] == m_set[i - 1]) {
            cout << "\n[!] The elements in a set must be unique.";
            throw NotAFieldException();
        }
    }
    if (not hasZero) {
        cout << "\n[!] A finite field must have the element '0'.";
        throw NotAFieldException();
    } else if (not hasOne) {
        cout << "\n[!] A finite field must have the element '1'.";
        throw NotAFieldException();
    }
}

void FiniteField::promptAdditionMapping() {
    cout << "\nNow you'll have to enter the addition mappings for all pairs.\n\n";
    m_additionMappings = new double *[m_size];
    for (int i = 0; i < m_size; i++) {
        m_additionMappings[i] = new double[m_size];
        for (int j = 0; j < m_size; j++) {
            double mapping;
            while (true) {
                cout << "Enter the result of " << m_set[i] << "+" << m_set[j] << ": ";
                if (cin >> mapping and find(m_set, m_set + m_size, mapping) != m_set + m_size) {
                    break;
                } else {
                    cout << "[!] Please enter a valid result.\n";
                    cin.clear();
                    cin.ignore(256, '\n');
                }
            }
            m_additionMappings[i][j] = mapping;
        }
    }
}

void FiniteField::promptMultiplicationMapping() {
    cout << "\nFinally, you'll have to enter the multiplication mappings for all pairs.\n\n";
    m_multiplicationMappings = new double *[m_size];
    for (int i = 0; i < m_size; i++) {
        m_multiplicationMappings[i] = new double[m_size];
        for (int j = 0; j < m_size; j++) {
            double mapping;
            while (true) {
                cout << "Enter the result of " << m_set[i] << "*" << m_set[j] << ": ";
                if (cin >> mapping and find(m_set, m_set + m_size, mapping) != m_set + m_size) {
                    break;
                } else {
                    cout << "[!] Please enter a valid result.\n";
                    cin.clear();
                    cin.ignore(256, '\n');
                }
            }
            m_multiplicationMappings[i][j] = mapping;
        }
    }
}

void FiniteField::assertIsField() {
    int zeroIndex, oneIndex;
    for (int i = 0; i < m_size; i++) {
        if (m_set[i] == 0) {
            zeroIndex = i;
        } else if (m_set[i] == 1) {
            oneIndex = i;
        }
    }
    for (int i = 0; i < m_size; i++) {
        if (m_additionMappings[i][zeroIndex] != m_set[i] or m_additionMappings[zeroIndex][i] != m_set[i]) {
            cout << "\n[!] '0' is not an identity element for the addition in the mappings.";
            throw NotAFieldException();
        }
        if (m_multiplicationMappings[i][oneIndex] != m_set[i] or
            m_multiplicationMappings[oneIndex][i] != m_set[i]) {
            cout << "\n[!] '1' is not an identity element for the multiplication in the mappings.";
            throw NotAFieldException();
        }
    }
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            if (m_additionMappings[i][j] != m_additionMappings[j][i]) {
                cout << "\n[!] The additive group is not commutative.";
                throw NotAFieldException();
            }
            if (m_multiplicationMappings[i][j] != m_multiplicationMappings[j][i]) {
                cout << "\n[!] The multiplication group is not commutative.";
                throw NotAFieldException();
            }
        }
    }
    for (int i = 0; i < m_size; i++) {
        unordered_map<double, int> lineMap;
        for (int j = 0; j < m_size; j++) {
            lineMap[m_additionMappings[i][j]]++;
            if (lineMap[m_additionMappings[i][j]] > 1) {
                cout << "\n[!] The additive group is not associative.";
                throw NotAFieldException();
            }
        }
        unordered_map<double, int> columnMap;
        for (int j = 0; j < m_size; j++) {
            columnMap[m_additionMappings[j][i]]++;
            if (columnMap[m_additionMappings[j][i]] > 1) {
                cout << "\n[!] The additive group is not associative.";
                throw NotAFieldException();
            }
        }
    }
    for (int i = 0; i < m_size; i++) {
        bool foundZeroOnLine = false;
        for (int j = 0; j < m_size; j++) {
            if (m_additionMappings[i][j] == 0) {
                foundZeroOnLine = true;
                break;
            }
        }
        if (not foundZeroOnLine) {
            cout << "\n[!] Not each element from the additive group is invertible.";
            throw NotAFieldException();
        }
    }
    for (int i = 1; i < m_size; i++) {
        bool foundOneOnLine = false;
        for (int j = 1; j < m_size; j++) {
            if (m_multiplicationMappings[i][j] == 1) {
                foundOneOnLine = true;
                break;
            }
        }
        if (not foundOneOnLine) {
            cout << "\n[!] Not each element from the multiplicative group (except 0) is invertible.";
            throw NotAFieldException();
        }
    }
}