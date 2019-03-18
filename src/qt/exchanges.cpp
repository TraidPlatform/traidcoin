#include "exchanges.h"
#include "ui_exchanges.h"
#include <QDesktopServices>
#include <QUrl>

Exchanges::Exchanges(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Exchanges)
{
    ui->setupUi(this);
}

Exchanges::~Exchanges()
{
    delete ui;
}

void Exchanges::on_websiteButton_clicked()
{
    QString websiteLink = "https://www.traid.tv/";
    QDesktopServices::openUrl(websiteLink);
}

void Exchanges::on_cryptoBridgeButton_clicked()
{
    QString cryptobridgeLink = "https://wallet.crypto-bridge.org/market/BRIDGE.TRAID_BRIDGE.BTC";
    QDesktopServices::openUrl(cryptobridgeLink);
}

void Exchanges::on_crex24Button_clicked()
{
    QString crexLink = "https://crex24.com/exchange/TRAID-BTC";
    QDesktopServices::openUrl(crexLink);
}

void Exchanges::on_whitePapperButton_clicked()
{
    QString whitepapperLink = "https://www.traid.tv/Traid_Whitepaper.pdf";
    QDesktopServices::openUrl(whitepapperLink);
}

void Exchanges::on_gitHubButton_clicked()
{
    QString githubLink = "https://github.com/TraidPlatform/traidcoin";
    QDesktopServices::openUrl(githubLink);
}

void Exchanges::on_annButton_clicked()
{
    QString annLink = "https://bitcointalk.org/index.php?topic=4722732.0";
    QDesktopServices::openUrl(annLink);
}

void Exchanges::on_poolButton_clicked()
{
    QString poolLink = "https://pool.traid.tv/";
    QDesktopServices::openUrl(poolLink);
}

void Exchanges::on_explorerButton_clicked()
{
    QString explorerLink = "https://explorer.traid.tv/";
    QDesktopServices::openUrl(explorerLink);
}

void Exchanges::on_cmcButton_clicked()
{
    QString cmcLink = "https://coinmarketcap.com/currencies/traid/";
    QDesktopServices::openUrl(cmcLink);
}

void Exchanges::on_discordButton_clicked()
{
    QString discordLink = "https://discord.gg/tEUt4aX";
    QDesktopServices::openUrl(discordLink);
}

void Exchanges::on_twitterButton_clicked()
{
    QString twitterLink = "https://twitter.com/traid_platform";
    QDesktopServices::openUrl(twitterLink);
}

void Exchanges::on_ytButton_clicked()
{
    QString ytLink = "https://www.youtube.com/channel/UCjoJNtjDmIiCNSzpAvixLGA";
    QDesktopServices::openUrl(ytLink);
}

void Exchanges::on_telegramButton_clicked()
{
    QString telegramLink = "https://t.me/traidplatform";
    QDesktopServices::openUrl(telegramLink);
}

void Exchanges::on_instagramButton_clicked()
{
    QString instagramLink = "https://www.instagram.com/traid_platform";
    QDesktopServices::openUrl(instagramLink);
}

void Exchanges::on_mediumButton_clicked()
{
    QString mediumLink = "https://medium.com/@traid_platform";
    QDesktopServices::openUrl(mediumLink);
}


void Exchanges::on_coinGeckoButton_clicked()
{
    QString geckoLink = "https://www.coingecko.com/en/coins/traid";
    QDesktopServices::openUrl(geckoLink);
}

void Exchanges::on_whatToMineButton_clicked()
{
    QString wtmLink = "https://whattomine.com/coins/274-traid-neoscrypt";
    QDesktopServices::openUrl(wtmLink);
}

void Exchanges::on_cryptoCompareButton_clicked()
{
    QString cmpLink = "https://www.cryptocompare.com/coins/traid/overview";
    QDesktopServices::openUrl(cmpLink);
}

void Exchanges::on_liveCoinWatchButton_clicked()
{
    QString liveCoinLink = "https://www.livecoinwatch.com/price/Traid-TRAID";
    QDesktopServices::openUrl(liveCoinLink);
}

void Exchanges::on_worldCoinIndexButton_clicked()
{
    QString wciLink = "https://www.worldcoinindex.com/coin/traid";
    QDesktopServices::openUrl(wciLink);
}
