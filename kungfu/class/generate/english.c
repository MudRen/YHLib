// english.c Ӣ����

#include <ansi.h>

inherit CHALLENGER;

void create()
{
        set_name("Ӣ����", ({ "english" }));
        set("long", "һ��Ӣ���ˡ�\n");
        set("gender", "����");
        set("age", 20);
        set("str", 40);
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
        set_skill("qishi-ji", 1);
        set_skill("club", 1);

        map_skill("club", "qishi-ji");
        map_skill("force", "xiyang-neigong");
        map_skill("dodge", "xiyang-boji");
        map_skill("parry", "qishi-ji");

        set("rank_info/rude", "��ë��");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: perform_action, "club.chong" :),
                (: perform_action, "club.juan" :),
        }));

        setup();

        carry_object("/clone/cloth/yinjia")->wear();
        carry_object("/clone/weapon/qishiji")->wield();
}

string challenge()
{
        set("opinion/msg", ({
                (random(2) ? "���������ʥ��ʿѫ�£��������Ӣ����Ů�����԰䷢��"
                           : "���������������ֳֳ�ꪣ����Ӧ��Ӣ�����Ļʼ���ʿ��"),
                (random(2) ? "����Ӣ�����ʼ���ʿ���������������ƣ����ڳ������"
                           : "��˵���������и��С���ǹ������ʿ����ǹ���ѳƵ����ǳ����뻯��"),
                (random(2) ? "�����ңԶ�ĵط�Զ�ȶ�����Ҳ���ǹ���Ϊ�����ˣ�"
                           : "�ţ���ì�����ڳ�̣����Ǳ仯���٣�������ս������ס�"),
        }));

        command(random(2) ? "haha" : "killair");
        switch (random(2))
        {
        case 0:
                return "������" + query("nation") + "����˵������ԭ"
                       "�����������ص�ǰ���д��д裡";

        default:
                return "����" + query("nation") + "�ʼ���ʿ�ŵ�" + name() + "����"
                       "ԭ��˭Ը�����һ�ϸߵͣ�";
        }
}

void unconcious()
{
        command("chat ������ô������ô��ô������");
        die();
}

void competition_with(object ob)
{
        command("say ̫���ˣ����Ǿͷָ��ߵͿ�����\n");
        ::competition_with(ob);
}

void lost()
{
        string *ob_list = ({
                "/clone/fam/etc/prize1",
                "/clone/fam/etc/prize2",
                "/clone/fam/etc/prize3",
                "/clone/fam/etc/prize4",
        });
        object ob;

        ob = new(ob_list[random(sizeof(ob_list))]);
        message_vision(HIY "$N" HIY "����һ�ˣ�����һ" + ob->query("unit") +
                       ob->name() + HIY "��\n\n" NOR, this_object());

        ob->move(environment());
        ::lost();
}
