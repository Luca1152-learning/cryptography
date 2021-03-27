#include "MainLoop.h"

void MainLoop::run() {
    while (promptCommand());
}

MainLoop::~MainLoop() {
    for (auto &field:m_fields) {
        delete field;
    }
}

bool MainLoop::promptCommand() {
    int commandChoice;
    while (true) {
        cout << "(1) List the current fields\n"
             << "(2) Add a new field\n"
             << "(3) Compute mathematical operations on a field\n"
             << "(4) Exit\n"
             << "Operation to perform (1-4): ";
        if (cin >> commandChoice and commandChoice >= 1 and commandChoice <= 4) {
            break;
        } else {
            cout << "\nPlease enter a valid choice.\n\n";
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
            cout << "\nPlease enter a valid choice.\n\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
    cout << "\n";

    FieldEquationsPrompter::promptForEquations(m_fields[fieldChoice - 1]);
}