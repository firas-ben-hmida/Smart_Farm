#ifndef chatbot_H
#define chatbot_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

QT_BEGIN_NAMESPACE
namespace Ui { class chatbot; }
QT_END_NAMESPACE

class chatbot : public QDialog
{
    Q_OBJECT

public:
    chatbot(QWidget *parent = nullptr);
    ~chatbot();

private slots:
    void sendMessage();
    void on_SendButton_clicked();
    void fetchTriviaQuestion(const QString& apiUrl);

private:
    Ui::chatbot *ui;
    QString generatechatbotReply(const QString& message);
    QString getRandomJoke();
    QString m_lastJoke;
    QNetworkAccessManager* networkManager;

    bool m_requestCooldown;

    struct Question {
        QString question;
        QStringList options;
        QString correctAnswer;
        bool isValid;

        Question() : isValid(false) {}

        void clear()
        {
            question.clear();
            options.clear();
            correctAnswer.clear();
            isValid = false;
        }
    };

    Question m_currentQuestion;
    QString decodeHtmlEntities(const QString& text);
};

#endif // chatbot_H
