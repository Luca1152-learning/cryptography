#include "MainLoop.h"

MainLoop::MainLoop() {}

void MainLoop::copyFieldsVector(const MainLoop &mainLoop) {
    for (auto field: mainLoop.m_fields) {
        auto *integersModuloNField = dynamic_cast<IntegersModuloNField *>(field);
        if (integersModuloNField) {
            IntegersModuloNField *newField = new IntegersModuloNField(*integersModuloNField);
            m_fields.push_back(newField);
        } else {
            auto *rationalField = dynamic_cast<RationalField *>(field);
            if (rationalField) {
                RationalField *newField = new RationalField(*rationalField);
                m_fields.push_back(newField);
            } else {
                auto *realField = dynamic_cast<RealField *>(field);
                if (realField) {
                    RealField *newField = new RealField(*realField);
                    m_fields.push_back(newField);
                } else {
                    auto *complexField = dynamic_cast<ComplexField *>(field);
                    if (complexField) {
                        ComplexField *newField = new ComplexField(*complexField);
                        m_fields.push_back(newField);
                    }
                }
            }
        }
    }
}

MainLoop::MainLoop(const MainLoop &mainLoop) {
    copyFieldsVector(mainLoop);
}

MainLoop &MainLoop::operator=(const MainLoop &mainLoop) {
    m_fields.clear();
    copyFieldsVector(mainLoop);
    return *this;
}

MainLoop::~MainLoop() {
    for (auto &field:m_fields) {
        delete field;
    }
}

void MainLoop::run() {
    while (promptCommand());
}

bool MainLoop::promptCommand() {
    int commandChoice;
    while (true) {
        cout << "(1) List the current fields\n"
             << "(2) Add a new field\n"
             << "(3) Compute mathematical operations on a field\n"
             << "(4) Check for fields isomorphism\n"
             << "(5) Exit\n"
             << "Operation to perform (1-5): ";
        if (cin >> commandChoice and commandChoice >= 1 and commandChoice <= 5) {
            break;
        } else {
            cout << "\n[!] Please enter a valid choice.\n\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
    cout << "\n";

    if (commandChoice == 1) {
        listAllFields("The current fields are:\n", true);
        return true;
    } else if (commandChoice == 2) {
        promptFieldCreation();
        return true;
    } else if (commandChoice == 3) {
        promptMathOperations();
        return true;
    } else if (commandChoice == 4) {
        promptFieldIsomorphism();
        return true;
    } else {
        return false;
    }
}

void MainLoop::listAllFields(string headerText, bool extraNewLineAtTheEnd) const {
    if (m_fields.size() == 0) {
        cout << "No fields were added so far!\n\n";
        return;
    }

    cout << headerText;
    for (int i = 0; i < m_fields.size(); i++) {
        cout << "(" << i + 1 << ") " << m_fields[i]->getName() << "\n";
    }
    if (extraNewLineAtTheEnd) {
        cout << "\n";
    }
}

void MainLoop::promptFieldCreation() {
    cout << "Choose the field you want to create.\n\n";
    try {
        auto field = FieldFactory::promptFieldCreation();
        m_fields.push_back(field);
        cout << "\nField successfully created! Now you can perform mathematical operations on it.\n\n";
    } catch (NotAFieldException e) {
        cout << "\n[!] The given structure is not a field. Try again.\n\n";
        promptFieldCreation();
    }
}

void MainLoop::promptMathOperations() const {
    if (m_fields.size() == 0) {
        listAllFields();
        return;
    }

    int fieldChoice;
    while (true) {
        listAllFields();
        cout << "The field to compute mathematical operations on (1-" << m_fields.size() << "): ";
        if (cin >> fieldChoice and fieldChoice >= 1 and fieldChoice <= m_fields.size()) {
            break;
        } else {
            cout << "\n[!] Please enter a valid choice.\n\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
    cout << "\n";

    FieldEquationsPrompter::promptForEquations(m_fields[fieldChoice - 1]);
}

void MainLoop::promptFieldIsomorphism() const {
    if (m_fields.size() < 1) {
        cout << "[!] At least one field has to be entered for this option to become available\n\n";
        return;
    }

    listAllFields();
    int firstField, secondField;
    while (true) {
        cout << "The first field (1-" << m_fields.size() << "): ";
        if (cin >> firstField and firstField >= 1 and firstField <= m_fields.size()) {
            break;
        } else {
            cout << "[!] Please enter a valid choice.\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
    while (true) {
        cout << "The second field (1-" << m_fields.size() << "): ";
        if (cin >> secondField and secondField >= 1 and secondField <= m_fields.size()) {
            break;
        } else {
            cout << "[!] Please enter a valid choice.\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }

    bool areIsomorphic = m_fields[firstField - 1]->isIsomorphicTo(m_fields[secondField - 1]);
    cout << "\nAre the two fields isomorphic: " << (areIsomorphic ? "YES" : "NO") << "\n\n";
}