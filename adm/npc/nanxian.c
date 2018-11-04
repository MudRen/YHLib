#include <ansi.h>

inherit NPC;
inherit F_DEALER;
inherit F_UNIQUE;

void create()
{
        set_name("����", ({ "nan xian", "nan", "xian" }));
        set("long", @LONG
����������ɼ���뷢�԰ס�������ò���ʵ
ȴΪ����ͷ���������������кųơ�����
���󡹵����͡���Ϊ��������а������ʱ����
�����������춯�صĴ�١���ƽ��ս��������
�ڱ�������ʧ���֡�
LONG);
        set("nickname", HIW "��������" NOR);
        set("title", HIC "����̩��" NOR);
        set("gender", "����" );
        set("age", 74);
        set("attitude", "friendly");
        set("max_jing", 50000);
        set("max_qi", 50000);
        set("max_jingli", 50000);
        set("jingli", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set("jiali", 350);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
        set("combat_exp", 12000000);

        set_skill("force", 500);
        set_skill("huntian-baojian", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("unarmed", 500);
        set_skill("sword", 500);
        set_skill("lunhui-jian", 500);
        set_skill("poison", 500);
        set_skill("medical", 500);
        set_skill("lingbo-weibu", 500);
        set_skill("qiankun-danuoyi", 500);
        set_skill("buddhism", 500);
        set_skill("taoism", 500);
        set_skill("literate", 500);
        set_skill("martial-cognize", 500);

        map_skill("force", "huntian-baojian");
        map_skill("parry", "qiankun-danuoyi");
        map_skill("unarmed", "huntian-baojian");
        map_skill("dodge", "lingbo-weibu");
        map_skill("sword", "lunhui-jian");

        prepare_skill("unarmed", "huntian-baojian");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hui" :),
                (: perform_action, "sword.hui" :),
                (: perform_action, "sword.hui" :),
                (: exert_function, "sword" :),
                (: exert_function, "sword" :),
                (: exert_function, "sword" :),
                (: exert_function, "recover" :),
                (: exert_function, "regenerate" :),
                (: exert_function, "powerup" :),
        }));

        set("inquiry", ([
                "name" : "����������һ�ִ��Ŷ��ѣ������к����壿",
                "����" : "�㾡���Ǹ������ļһ�������",
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

        if (! clonep(this_object()))
        {
                move("/d/xiakedao/haibin");
                message_vision(WHT "\nͻȻ������ǰһ��������ƺ����˸�"
                               "��Ӱ��\n" NOR, this_object());
                set("startroom", "/d/xiakedao/haibin");
        }
}

// ����ѯ��
mixed accept_ask(object who, string topic)
{
        return ULTRA_D->accept_ask(this_object(), who, topic);
}

void fight_ob(object ob)
{
        if (is_fighting(ob))
                return;

        command("say �ߣ���֪���");
        command("exert powerup");
        command("exert sword");
        ::fight_ob(ob);
}

int accept_fight(object who)
{
        command("say û��Ȥ��");
        return 0;
}

int accept_ansuan(object who)
{
        return notify_fail("����밵�㣬������ǰһ��������̫�����\n");
}

void unconcious()
{
        die();
}
