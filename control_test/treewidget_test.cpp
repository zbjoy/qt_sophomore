#include "treewidget_test.h"
#include "ui_treewidget_test.h"
#include <QPushButton>
#include <QTreeWidget>
#include <QStringList>

treeWidget_test::treeWidget_test(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::treeWidget_test)
{
    ui->setupUi(this);
    QTreeWidget* widget = new QTreeWidget(this);

    this->resize(800, 600);
    this->move(600, 200);
    widget->resize(this->width(), this->height());

    QPushButton* btn = new QPushButton("关闭", widget);
    btn->move(600, 400);
    connect(btn, &QPushButton::clicked, [=](){
        emit closeTreeWidget();
    });

    widget->setHeaderLabels(QStringList() << "英雄" << "力量");
    // QTreeWidgetItem* power = new QTreeWidgetItem("力量");
    // QTreeWidgetItem* speed = new QTreeWidgetItem("敏捷");
    // QTreeWidgetItem* smart = new QTreeWidgetItem("智力");
    QTreeWidgetItem* power = new QTreeWidgetItem(QStringList() << "力量");
    QTreeWidgetItem* speed = new QTreeWidgetItem(QStringList() << "敏捷");
    QTreeWidgetItem* smart = new QTreeWidgetItem(QStringList() << "智力");
    widget->addTopLevelItem(power);
    widget->addTopLevelItem(speed);
    widget->addTopLevelItem(smart);
    QStringList heroL1,heroL2,heroM1,heroM2,heroZ1,heroZ2;
    heroL1 << "刚背猪" << "前排坦克，能在吸收伤害的同时造成可观的范围输出";
    heroL2 << "船长" << "前排坦克，能肉能输出能控场的全能英雄";

    heroM1 << "月骑" << "中排物理输出，可以使用分裂利刃攻击多个目标";
    heroM2 << "小鱼人" << "前排战士，擅长偷取敌人的属性来增强自身战力";

    heroZ1 << "死灵法师" << "前排法师坦克，魔法抗性较高，拥有治疗技能";
    heroZ2 << "巫医" << "后排辅助法师，可以使用奇特的巫术诅咒敌人与治疗队友";
    // power->addChild(heroL1);
    // power->addChild(heroL2);

    // speed->addChild(heroM1);
    // speed->addChild(heroM2);

    // smart->addChild(heroZ1);
    // smart->addChild(heroZ2);

    power->addChild(new QTreeWidgetItem(heroL1));
    power->addChild(new QTreeWidgetItem(heroL2));

    speed->addChild(new QTreeWidgetItem(heroM1));
    speed->addChild(new QTreeWidgetItem(heroM2));

    smart->addChild(new QTreeWidgetItem(heroZ1));
    smart->addChild(new QTreeWidgetItem(heroZ2));
}

treeWidget_test::~treeWidget_test()
{
    delete ui;
}
