// msn.c ��Ϣ������
// by vin

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC "��Ϣ������" NOR, ({ "msg" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "
������������������������������������������������

����ʹ�� (" HIY "setrank" NOR ")���趨��Ϣ���⣬ȱʡΪ�鿴��ǰ
���⡣������(" HIY "none" NOR ")���趨������Ԥ����⡣\n
ʹ�� (" HIY "msn" NOR ")ʱ�����г���Ϣ����ʱ��Ϸ�е�������Ҿ�
�ܿ�������Ϣ�ķ���������ʹ���ߵ�����Ϊ" HIC "$N" NOR "��ʹ����
��idΪ" HIC "$I" NOR "���������Ϊ" HIC "$S$" NOR "���������Ϊ"
HIC "$B$" NOR "��������ɫ
���ſɲ鿴(" HIY "help nick" NOR ")�º��趨��\n
ʹ��(" HIY "test" NOR ")Ϊ����׼����ʾ����Ϣ����ʹ���������ʱ
��Ϣֻ��ʹ�����ܹ�������

������������������������������������������������
\n");
                set("value", 0);
                set("rank", HIY "��������Ϣ��" NOR);
        }
}

void init()
{
        add_action("do_msn", "msn");
        add_action("do_set", "setrank");
        add_action("do_test", "test");
}

int do_set(string arg)
{
        string msg;
        object me = this_player();

        if (! arg)
                return notify_fail("��ǰ������" + query("rank") + "��Ϊ"
                                   "���⣬������趨ʲô����Ϣ���⣿\n");

        if (arg == "none")
        {
                set("rank", HIY "��������Ϣ��" NOR);
                write("�㽫��Ϣ���������ˡ�\n");
                return 1;
        }

        msg = arg;

        if (CHINESE_D->check_length(msg) > 20)
                return notify_fail("��Ϣ���ⲻ�˹�����\n");

        if (strlen(filter_color(msg)) > 30)
                return notify_fail("��Ϣ���ⲻ�˹�����\n");

        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MAG$", MAG);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg = replace_string(msg, "$S$", BLINK);

        set("rank", msg + NOR);
        write("���趨������Ϣ���⡣\n");
        return 1;
}

int do_test(string arg)
{
        string msg, chat;
        object me = this_player();

        if (! arg || arg == "")
                msg = WHT + me->name(1) + WHT "[" +
                      me->query("id") + "]������";
        else
                msg = arg;

        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MAG$", MAG);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg = replace_string(msg, "$S$", BLINK);
        msg = replace_string(msg, "$B$", BEEP);
        msg = replace_string(msg, "$N", me->name(1));
        msg = replace_string(msg, "$I", "[" + me->query("id") + "]");

        chat = query("rank") + NOR + msg + HIG "�������С�\n" NOR;
        write(chat);
        return 1;
}

int do_msn(string arg)
{
        string msg, chat;
        object me = this_player();

        if (! arg || arg == "")
                msg = WHT + me->name(1) + WHT "[" +
                      me->query("id") + "]������";
        else
                msg = arg;

        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MAG$", MAG);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg = replace_string(msg, "$S$", BLINK);
        msg = replace_string(msg, "$B$", BEEP);
        msg = replace_string(msg, "$N", me->name(1));
        msg = replace_string(msg, "$I", "[" + me->query("id") + "]");

        chat = query("rank") + NOR + msg + NOR "\n";

        shout(chat);
        write(chat);
        return 1;
}

int query_autoload()
{
        return 1;
}
