#ifndef CRYPTOGRAPHY_FINITEFIELD_H
#define CRYPTOGRAPHY_FINITEFIELD_H

#include <unordered_map>
#include "BaseMathField.h"
#include "../math/MathUtils.h"
#include "../exceptions/NotAFieldException.h"
#include "../number/FiniteFieldNumber.h"

class FiniteField : public BaseMathField {
public:
    FiniteField();

    FiniteField(const FiniteField &finiteField);

    FiniteField &operator=(const FiniteField &finiteField);

    bool operator==(const FiniteField &finiteField) const;

    bool operator!=(const FiniteField &finiteField) const;

    string getName() const override;

    int getSize() const;

    double *getSet() const;

    double **getAdditionMappings() const;

    double **getMultiplicationMappings() const;

    int getIndexInSet(double value) const;

    bool isIsomorphicTo(BaseMathField *field) const override;

    void promptCreation();

    FiniteFieldNumber createNumber();

    ~FiniteField();

private:
    int m_size;
    double *m_set, **m_additionMappings, **m_multiplicationMappings;

    void copyFiniteField(const FiniteField &finiteField);

    void deallocateSpace();

    void promptSet();

    void promptAdditionMapping();

    void promptMultiplicationMapping();

    void assertIsField();
};

#endif //CRYPTOGRAPHY_FINITEFIELD_H
