#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��̶��ͷ");
        set("long", @LONG
����ֻ������ҫ�ۣ������˱ǣ����Ǳ�����أ���Ŀ�Ĺˣ�
ֻ��������ݣ�����ͬһ������Ļ�԰��Ȼ��Ӱ�������Ĺ���
�ˡ�ʮ��������һ��é��(house)�� ��������������ﾲ����
�ģ������������Ω���۷������΢�졣���̶͸������
������
LONG);
        set("item_desc", ([
                "house" : NOR + YEL "����é���ƾɲ������ƺ��ܾ�û�������ˡ�\n" NOR,
        ]));

        set("exits", ([
                "enter" : __DIR__"house",
        ]));
                 
        set("no_clean_up", 0);

        setup();
}

void init()
{       
        add_action("do_jump", ({ "tiao", "jump" }));
}

int do_jump(string arg)
{
        object me = this_player();
        object ob;


        if (! arg || arg != "tan")
                return notify_fail("��Ҫ���Ķ�����\n");

        if (me->is_busy())
                return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
                return notify_fail("�㻹���Ȱ�����ǰ����һ�������˵��\n");

        write(HIC "��������̶��˳�ƶ���æ�����������ȥ��������ʱ���㵽��\n"
                  "��̶��һ�࣬���Ȳ�����������Ծ��ˮ�档\n\n" NOR);

        if (! ob = find_object(__DIR__"underya"))
               ob = load_object(__DIR__"underya");

        me->move(ob);
       
        return 1;

}
