#ifndef EXCHANGES_H
#define EXCHANGES_H

#include <QWidget>

namespace Ui {
class Exchanges;
}

class Exchanges : public QWidget
{
    Q_OBJECT

public:
    explicit Exchanges(QWidget *parent = 0);
    ~Exchanges();

private slots:

    void on_websiteButton_clicked();

    void on_cryptoBridgeButton_clicked();

    void on_crex24Button_clicked();

    void on_whitePapperButton_clicked();

    void on_gitHubButton_clicked();

    void on_annButton_clicked();

    void on_poolButton_clicked();

    void on_explorerButton_clicked();

    void on_cmcButton_clicked();

    void on_discordButton_clicked();

    void on_twitterButton_clicked();

    void on_ytButton_clicked();

    void on_telegramButton_clicked();

    void on_instagramButton_clicked();

    void on_mediumButton_clicked();

    void on_coinGeckoButton_clicked();

    void on_whatToMineButton_clicked();

    void on_cryptoCompareButton_clicked();

    void on_liveCoinWatchButton_clicked();

    void on_worldCoinIndexButton_clicked();

private:
    Ui::Exchanges *ui;
};

#endif // EXCHANGES_H
