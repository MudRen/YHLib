#include <room.h>
#include <ansi.h>
#include <getconfig.h>
inherit ROOM;

int do_look(string arg);

void create()
{
        set("short", "Ӣ�ۻ��");
        set("long", @LONG
Ӣ�ۻ��Ҳ�Ƿ���ү�ļ�ҵ������������ˣ�����������
����ͷ�ġ�Ӣ�ۻ����Χ�ź�ѹѹ��һȺ�ˣ��Ϸ���һ�Ƚ���
�رյ�С�š�ֻ����ÿ��һ�εĵ�������ʱ���ϰ��졹������
�ŻὫ���򿪣����������������̼֡�С���Թ��ŵ�һ���
ľ����(paizi)�ϱ�д�Ÿ��ҵ��������ĵ׼ۡ�
LONG);

        set("no_fight", 1);
        set("no_beg", 1);
        set("no_steal", 1);

        set("exits", ([
               "north" : __DIR__"street2",
        ]));

        set("objects", ([
                __DIR__"npc/fengyiming" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_look", "look");

        if (wiz_level(this_player()) >= 3)
        {
                add_action("do_open", "open");
                add_action("do_close", "close");
        }
}

int valid_leave(object me, string dir)
{
        if (query("exits/south"))
        {
                if ((me->query("balance") < 5000000
                   || me->query("weiwang") < 3000)
                   && dir == "south" && ! wizardp(me))
                        return notify_fail(CYN "��һ����ס�㣬��Ц�����Ը��µĲ�"
                                           "���͵�λ���в����Խ�ȥ��\n" NOR);
        }
        return ::valid_leave(me);
}

int do_open()
{
        object me = this_player();

        if (query("exits/south"))
                return notify_fail("���Ѿ��ǿ��ŵ��ˡ�\n");

        set("exits/south", __DIR__"pmc");

        message_vision(HIY "$N" HIY "����һ�ƣ���ͨ��Ӣ�ۻ�ݵ�"
                       "С�ſ����ˡ�\n" NOR, me);

        shout(HIY "���̽紫�š�" NOR + WHT + me->name() + WHT "[" +
              me->query("id") + WHT "]�����˷�ɽӢ�ۻ�ݵĵ�����"
              "����Ĵ��š�\n" NOR);

        write("�㿪ͨ�˵����������·����\n");
        return 1;
}

int do_close()
{
        object me = this_player();

        if (! query("exits/south"))
                return notify_fail("���Ѿ��ǹ��ŵ��ˡ�\n");

        delete("exits/south");
        message_vision(WHT "$N" WHT "˳��һ������ͨ������������"
                       "С�Ź����ˡ�\n" NOR, me);
        return 1;
}

int do_look(string arg)
{
        int i, g;
        string msg;
        mapping *shop_record;

        if (arg != "paizi")
                return 0;

        if (! query("exits/south"))
        {
                write("������δ���������̵�ʱ�䡣\n");
                return 1;
        }

        shop_record = SHOP_D->query_shop();

        msg = LOCAL_MUD_NAME() + "���������׼۱�\n"NOR;
        msg += HIY "������������������������������������������������������\n" NOR;

        msg += sprintf(HIY "��" NOR + WHT " %-18s%-18s%-13s" HIY "��\n" NOR,
                       "����λ��",
                       "��������",
                       "�����׼�");

        msg += HIY "������������������������������������������������������\n" NOR;

        for (i = 0; i < sizeof(shop_record); i++)
        {
                g = shop_record[i]["price"];
                msg += sprintf(HIY "��" HIC " %s����           "
                               HIG "%-16s" NOR +
                               YEL "�ƽ�" + chinese_number(g) +
                               "��    " HIY "��\n" NOR,
                               shop_record[i]["id"],
                               shop_record[i]["name"]);
        }
        msg += HIY "������������������������������������������������������\n" NOR;
        msg += WHT "�ܹ���" + chinese_number(sizeof(shop_record)) +
               WHT "�ҵ��̵ȴ�������\n";
        write(msg);
        return 1;
}
