#ifndef HEXSTRINGVALIDATOR_H
#define HEXSTRINGVALIDATOR_H
#include <QValidator>

class HexStringValidator : public QValidator {
public:
    HexStringValidator(QObject * parent=0) : QValidator(parent) {}

public:
    virtual void fixup(QString &input) const {
        QString temp;
        int index = 0;

            // every 2 digits insert a space if they didn't explicitly type one
        Q_FOREACH(QChar ch, input) {
            if(std::isxdigit(ch.toLatin1())) {

                if(index != 0 && (index & 1) == 0) {
                    temp += ' ';
                }

                temp += ch.toUpper();
                ++index;
            }
        }

        input = temp;
    }

    virtual State validate(QString &input, int &pos) const {
        if(!input.isEmpty()) {
            // TODO: can we detect if the char which was JUST deleted
            // (if any was deleted) was a space? and special case this?
            // as to not have the bug in this case?

            const int charPos  = pos - input.left(pos).count(' ');
            int chars           = 0;
            fixup(input);

            pos = 0;

            while(chars != charPos) {
                if(input[pos] != ' ') {
                    ++chars;
                }
                ++pos;
            }

            // favor the right side of a space
            if(input[pos] == ' ') {
                ++pos;
            }
        }
        return QValidator::Acceptable;
    }
};
#endif // HEXSTRINGVALIDATOR_H
