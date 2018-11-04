#include <ansi.h>

inherit KNOWER;
inherit F_VENDOR;

string ask_me();

void create()
{
        set_name("С��", ({ "xiao fan", "xiao", "fan" }));
        set("gender", "����" );
        set("age", 32);
        set("long", "���Ǹ�С����������������ʵʵ�������\n"
                    "������Ƕ��ͱ��ˡ�\n");
        set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/stick",
                __DIR__"obj/bottle",
                __DIR__"obj/egg",
                "/d/xingxiu/obj/fire",
        }));
        set("inquiry", ([
                "ҩ��"   : (: ask_me :),
                "����"   : (: ask_me :),
                "������" : (: ask_me :),
        ]));

        set("count", 3);

        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        add_money("coin", 100);
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy", "buy");
}

string ask_me()
{
        object me = this_player();

        if (query("count") < 1)
	{
                return "ʵ�ڶԲ�ס������������Ҳû���ˡ�\n";
        } else
        if (me->query_temp("tmark/ҩ"))
	{
                return "�����ϴ�����û��������ô���µ��ˡ�\n";
        } else
	{
                me->set_temp("tmark/ҩ", 1);
                return "�ҵ�����ɭ���в�ҩ������������һЩ��ҩ�ģ�Ҫ����Ƚ�Ǯ��\n";
        }
}

int accept_object(object who, object ob)
{
        object obj;

        if (! ob->query("money_id"))
	{
                write(CYN "С�������˵��������������ʲô��\n" NOR);
                return 0;
	}

        if (query("count") < 1)
	{
                write(CYN "С����Ǹ��˵����ʵ�ڶԲ�ס������������Ҳû���ˣ�\n" NOR);
                return 0;
	}

        if (! who->query_temp("tmark/ҩ"))
	{
                write(CYN "С���ɻ��˵�������ֲ�����ؤ����û�¸���Ǯ���\n" NOR);
                return 0;
	}

        if (ob->value() < 10000)
	{
                write(CYN "С����Ц��˵�����ٺ٣�������ô��Ǯ�ġ�\n" NOR);
                return 0;
	}

        obj = new(__DIR__"obj/shouwu");
        obj->move(this_object());

        add("count", -1);
        command("give he shouwu to " + who->query("id"));
        write(CYN "С��˵������Ȼ���������Ǯ����ζҩ�ɾ͹����ˡ�\n" NOR);
        return 1;
}
