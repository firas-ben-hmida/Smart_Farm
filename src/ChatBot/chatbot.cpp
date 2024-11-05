#include "chatbot.h"
#include "ui_chatbot.h"
#include <random>
#include <cstdlib>
#include <ctime>
#include <QJsonArray>

chatbot::chatbot(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::chatbot),
    networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    connect(ui->SendButton, &QPushButton::clicked, this, &chatbot::on_SendButton_clicked);
}

chatbot::~chatbot()
{
    delete ui;
}

QString chatbot::getRandomJoke()
{
    QStringList jokes;
    jokes << "Pourquoi les scientifiques ne font-ils pas confiance aux atomes ? Parce qu'ils composent tout !"
          << "Pourquoi le vélo est-il tombé ? Parce qu'il était trop fatigué !"
          << "Comment appelle-t-on des spaghettis faux ? Un impasta !"
          << "Pourquoi les œufs ne racontent-ils pas de blagues ? Parce qu'ils pourraient éclater de rire !"
          << "Comment appelle-t-on un train qui transporte du chewing-gum ? Un train à mâcher !";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, jokes.size() - 1);
    int index = dist(gen);
    return jokes[index];
}

QString chatbot::generatechatbotReply(const QString& message)
{
    QString reply;
    QString lowercaseMessage = message.toLower();

    if (lowercaseMessage.contains("bonjour") || lowercaseMessage.contains("salut"))
    {
        reply = "Bonjour ! , Comment puis-je vous aider ?";
    }
    else if (lowercaseMessage.contains("comment ça va"))
    {
        reply = "Je vais bien, merci ! Et toi ?";
    }
    else if (lowercaseMessage.contains("bien") || lowercaseMessage.contains("bon"))
    {
        reply = "C'est super à entendre !";
    }
    else if (lowercaseMessage.contains("mal"))
    {
        reply = "Je suis désolé d'apprendre cela.";
    }
    else if (lowercaseMessage.contains("mon nom"))
    {
        reply = "Je suis désolé, mais je ne connais pas ton nom.";
    }
    else if (lowercaseMessage.contains("blague"))
    {
        QString joke = getRandomJoke();
        m_lastJoke = joke;
        reply = joke;
    }
    else if (lowercaseMessage.contains("une autre") && lowercaseMessage.contains("blague"))
    {
        if (!m_lastJoke.isEmpty())
        {
            QString anotherJoke = getRandomJoke();
            m_lastJoke = anotherJoke;
            reply = anotherJoke;
        }
        else
        {
            reply = "Désolé, je n'ai pas d'autre blague pour le moment.";
        }
    }
    else if (lowercaseMessage.contains("triste"))
    {
        reply = "Ne sois pas triste. Tout ira bien. Remonte le moral !";
    }
    else if (lowercaseMessage.contains("heureux"))
    {
        reply = "Ravi d'entendre ça !";
    }
    else if (lowercaseMessage.contains("merci"))
    {
        reply = "De rien !";
    }
    else if (lowercaseMessage.contains("ok"))
    {
        reply = "Oui, d'accord !";
    }
    else if (lowercaseMessage.contains("jouer à un jeu") || lowercaseMessage.contains("jouer un jeu"))
    {
        reply = "Bien sûr ! Jouons à Pierre, Feuille, Ciseaux. Choisis-en un : pierre, feuille ou ciseaux.";
    }
    else if (lowercaseMessage.contains("pierre") || lowercaseMessage.contains("feuille") || lowercaseMessage.contains("ciseaux"))
    {
        srand(time(0));
        int computerMove = rand() % 3;
        QString userMove;
        if (lowercaseMessage.contains("pierre"))
        {
            userMove = "pierre";
        }
        else if (lowercaseMessage.contains("feuille"))
        {
            userMove = "feuille";
        }
        else if (lowercaseMessage.contains("ciseaux"))
        {
            userMove = "ciseaux";
        }
        QString result;
        if ((userMove == "pierre" && computerMove == 2) || (userMove == "feuille" && computerMove == 0) || (userMove == "ciseaux" && computerMove == 1))
        {
            result = "Tu gagnes !";
        }
        else if (userMove == "pierre" && computerMove == 1)
        {
            result = "Je gagne !";
        }
        else if (userMove == "feuille" && computerMove == 2)
        {
            result = "Je gagne !";
        }
        else if (userMove == "ciseaux" && computerMove == 0)
        {
            result = "Je gagne !";
        }
        else
        {
            result = "C'est une égalité !";
        }
        reply = "Tu as choisi " + userMove + ". J'ai choisi ";
        if (computerMove == 0)
        {
            reply += "pierre.";
        }
        else if (computerMove == 1)
        {
            reply += "feuille.";
        }
        else if (computerMove == 2)
        {
            reply += "ciseaux.";
        }
        reply += " " + result;
    }
    else if (lowercaseMessage.contains("ton nom"))
    {
        reply = "Je n'ai en réalité pas de nom. Mais tu peux m'appeler 'Mon chatbot'.";
    }
    else if (lowercaseMessage.contains("quiz") || lowercaseMessage.contains("question") || lowercaseMessage.contains("suivant"))
    {
        QString apiUrl = "https://opentdb.com/api.php?amount=1&category=18&difficulty=easy&type=multiple";
        fetchTriviaQuestion(apiUrl);
        return "";
    }
    else if (lowercaseMessage.contains("vache"))
    {
        reply = "Les vaches sont des animaux domestiques connus pour leur douceur. Elles fournissent du lait, qui peut être produit pendant environ 10 mois après la mise bas. Les vaches doivent être vaccinées pour prévenir certaines maladies, et elles mangent généralement deux à trois fois par jour, en fonction de leur régime alimentaire. Les soins réguliers, comme la traite, sont également essentiels.";
    }
    else if (lowercaseMessage.contains("mouton"))
    {
        reply = "Les moutons sont des animaux herbivores élevés pour leur laine, leur viande et leur lait. Ils se déplacent généralement en troupeaux et doivent être protégés contre les prédateurs. Les moutons ont besoin de vaccins pour prévenir des maladies comme la clavelée et la pneumonie. Ils sont souvent nourris deux fois par jour, en particulier pendant les périodes de gestation.";
    }
    else if (lowercaseMessage.contains("poule"))
    {
        reply = "Les poules sont des oiseaux domestiques principalement élevés pour leurs œufs et leur viande. Elles doivent être protégées des maladies par des vaccinations. Les poules sont généralement nourries trois fois par jour, et leur cycle de ponte peut être influencé par la lumière du jour et leur alimentation.";
    }
    else
    {
        reply = "Je suis désolé, je n'ai pas bien compris. Peux-tu reformuler ton message ?";
    }

    return reply;
}

void chatbot::on_SendButton_clicked()
{
    sendMessage();
}

void chatbot::sendMessage()
{
    QString message = ui->messageTextEdit->toPlainText();
    message = message.trimmed();
    if (message.isEmpty())
    {
        ui->messageTextEdit->clear();
        return;
    }
    ui->chatDisplayTextEdit->append("Utilisateur : " + message);
    ui->messageTextEdit->clear();

    if (m_currentQuestion.isValid && !m_currentQuestion.options.isEmpty())
    {
        bool isValidAnswer = false;
        int selectedOption = message.toInt(&isValidAnswer);
        if (isValidAnswer && selectedOption >= 1 && selectedOption <= m_currentQuestion.options.size())
        {
            QString userAnswer = m_currentQuestion.options[selectedOption - 1];
            if (userAnswer == m_currentQuestion.correctAnswer)
            {
                ui->chatDisplayTextEdit->append("chatbot : Réponse correcte !");
            }
            else
            {
                ui->chatDisplayTextEdit->append("chatbot : Réponse incorrecte. La réponse correcte est : " + m_currentQuestion.correctAnswer);
            }
        }
        else
        {
            ui->chatDisplayTextEdit->append("chatbot : Réponse invalide. Veuillez fournir un numéro d'option valide.");
        }

        m_currentQuestion.clear();
    }
    else
    {
        QString reply = generatechatbotReply(message);
        if (!reply.isEmpty())
        {
            ui->chatDisplayTextEdit->append("chatbot : " + reply);
        }
    }
}
void chatbot::fetchTriviaQuestion(const QString& apiUrl)
{
    QNetworkRequest request;
    request.setUrl(QUrl(apiUrl));

    QNetworkReply* reply = networkManager->get(request);
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            QJsonDocument jsonDoc(QJsonDocument::fromJson(response));
            QJsonObject jsonObject = jsonDoc.object();
            QJsonArray results = jsonObject["results"].toArray();
            if (!results.isEmpty()) {
                QJsonObject triviaQuestion = results[0].toObject();
                m_currentQuestion.question = triviaQuestion["question"].toString();
                m_currentQuestion.correctAnswer = triviaQuestion["correct_answer"].toString();
                QJsonArray incorrectAnswers = triviaQuestion["incorrect_answers"].toArray();
                for (const QJsonValue& value : incorrectAnswers)
                {
                    m_currentQuestion.options.append(value.toString());
                }
                m_currentQuestion.options.append(m_currentQuestion.correctAnswer);
                std::random_device rd;
                std::mt19937 g(rd());
                std::shuffle(m_currentQuestion.options.begin(), m_currentQuestion.options.end(), g);

                m_currentQuestion.isValid = true; // Mark the current question as valid
                ui->chatDisplayTextEdit->append("chatbot: " + m_currentQuestion.question);
                for (int i = 0; i < m_currentQuestion.options.size(); ++i)
                {
                    ui->chatDisplayTextEdit->append(QString::number(i + 1) + ". " + m_currentQuestion.options[i]);
                }
            }
        } else {
            ui->chatDisplayTextEdit->append("chatbot: Failed to fetch trivia question. Please try again later.");
        }
        reply->deleteLater(); // Cleanup the reply object
    });
}


QString chatbot::decodeHtmlEntities(const QString& text)
{
    QString decodedText = text;
    decodedText.replace("&quot;", "\"");
    decodedText.replace("&amp;", "&");
    decodedText.replace("&lt;", "<");
    decodedText.replace("&gt;", ">");
    decodedText.replace("&#039;", "'");
    return decodedText;
}
