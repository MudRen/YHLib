// smith.c

#include <ansi.h>

inherit "/inherit/char/smith.c";

mixed ask_back();

void create()
{
        set_name("����", ({ "tie jiang", "tie", "smith" }));
	set("title", "�������ϰ�");
	set("shen_type", 1);

        set("gender", "����" );
        set("age", 33);
        set("long", "����������ǯ��סһ����ȵ�����Ž�¯�С�\n");

        set("combat_exp", 400);
	set("attitude", "friendly");
        set("vendor_goods",({
                "/clone/weapon/changjian",
                "/clone/weapon/hammer",
                "/clone/weapon/tudao",
		"/clone/weapon/dagger",
                "/clone/weapon/tiegun",
                "/clone/weapon/gangdao",
                "/clone/cloth/tiejia",
                "/d/item/obj/jingtie",
                "/clone/weapon/arrow",
                "/clone/weapon/wolfarrow",
                "/clone/weapon/bow",
                "/clone/weapon/longbow",
        }));

        set("inquiry", ([
                "����" : (: ask_me :),
                "job"  : (: ask_me :),
                "Ѫ���ޱ�" : (: ask_back :),
        ]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

varargs int receive_damage(string type, int n, object who)
{
        if (! objectp(who) || ! interactive(who) || who == this_object())
                return 0;

        tell_object(who, HIR "�㷢��" + name() +
                    HIR "����һЦ����Ȼ����һ���ļ£�����һ���㱡�\n" NOR);
        return who->receive_damage(type, n, this_object());
}

varargs int receive_wound(string type, int n, object who)
{
        if (! objectp(who) || ! interactive(who) || who == this_object())
                return 0;

        tell_object(who, RED "�����" + name() +
                    RED "�����Ц��ֻ���û�����һʹ��ֱ��������\n" NOR);
        return who->receive_wound(type, n, this_object());
}

mixed ask_back()
{
        object me;

        me = this_player();
        if (me->query("family/family_name") != "Ѫ����")
        {
                message_vision("$N�Թ��Եĸɻ����û������$n��˵ʲô��\n",
                               this_object(), me);
                return -1;
        }

        message_sort(HIY "\n$N" HIY "�͵�̧��ͷ��������˫Ŀ�������´�����$n"
                     HIY "��һ�����΢΢���˵�ͷ��$N" HIY "�漴�������еĻ�"
                     "�ƣ�����������������ó�ʱ���ˣ������������˵�ձ���"
                     "��$p��������ȥ��\n\n" NOR, this_object(), me);

        me->move("/d/city/xdmidao4");
        tell_object(me, CYN + name() + "˵�������������һֱ���Ͼ����ˡ�\n"
                        HIC + name() + "˵��㼱��ææ���˻�ȥ��\n" NOR);
        return -1;
}
