// european.c ������

#include <ansi.h>

inherit CHALLENGER;

void create()
{
        set_name("������", ({ "european" }));
        set("long", "һ�������ˡ�\n");
        set("gender", "����");
        set("age", 20);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        // the follow 5 setting has no use
        set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);
        set("jiali", 100);
        set("shen", -1000);

        set("combat_exp", 3000000);
        set("scale", 100);

        set_skill("force", 1);
        set_skill("xiyang-neigong", 1);
        set_skill("dodge", 1);
        set_skill("xiyang-boji", 1);
        set_skill("parry", 1);
        set_skill("xiyang-jian", 1);
        set_skill("sword", 1);

        map_skill("sword", "xiyang-jian");
        map_skill("force", "xiyang-neigong");
        map_skill("dodge", "xiyang-boji");
        map_skill("parry", "xiyang-jian");

        set("rank_info/rude", "��ë��");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: perform_action, "sword.ci" :),
                (: perform_action, "sword.lian" :),
        }));

        setup();

        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/xiyang-sword")->wield();
}

string challenge()
{
        set("opinion/msg", ({
                (random(2) ? "�������Ծ�˵�Ǳȶ���˹��Ī˹�ƻ�ҪңԶ��������"
                           : "����������ʿ�������������˴�һ����"),
                (random(2) ? "�ǰ���ңԶ�ĵط����似Ҳ����Ϊ���ء�"
                           : "�ţ����������˴̻���������������������"),
                (random(2) ? "�����ңԶ�ĵط�������Ҳ���ǹ���Ϊ�����ˣ�"
                           : "��������Ȼע��ʵսЧ����������Ȼ�㲻�����ϳ˽�����"),
        }));

        command(random(2) ? "haha" : "killair");
        switch (random(2))
        {
        case 0:
                return "������" + query("nation") + "����˵������ԭ"
                        "�����������ص�ǰ���д��д裡";

        default:
                return "����" + query("nation") + "��" + name() + "��������"
                       "ԭ��û����Ը����ұ���һ�����գ�";
        }
}

void unconcious()
{
        command("chat ������ô������ô��ô������");
        die();
}

void competition_with(object ob)
{
        command("say �ðɣ����Ǿͷָ��ߵͿ�����\n");
        ::competition_with(ob);
}

void lost()
{
        string *ob_list = ({
                "/clone/fam/etc/prize1",
                "/clone/fam/etc/prize3",
                "/clone/fam/etc/prize4",
                "/clone/fam/etc/prize5",
        });
        object ob;

        ob = new(ob_list[random(sizeof(ob_list))]);
        message_vision(HIY "$N" HIY "����һ�ˣ�����һ" + ob->query("unit") +
                       ob->name() + HIY "��\n\n" NOR, this_object());

        ob->move(environment());
        ::lost();
}

