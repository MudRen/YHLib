#include <ansi.h>

inherit ROOM;
string look_pubu();

void create()
{
    set("short", YEL"��ɽ"NOR);
        set("long", @LONG
����ǰ������һ���޴�ļ�ɽ��һ���ٲ��Ӽ�ɽ��к����������ע��
ǰ���һ��������У�����������������кˮͨ����������ˮȴ�������硣
���ư�Ϊ�������԰��Ҳ��֪�����˶���������������
LONG    );
        set("exits", ([
                "east" : __DIR__"hhyuan-1",
        ]));

        set("item_desc", ([
//                "pubu" : (: look_pubu :),
        ]));

        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();
}

string look_pubu()
{
        return @DESC
����һ�ɱ��ڲ�Ϣ���ٲ����ٲ��ĺ����ƺ���Լ�и�С�ţ����ƺ����Դ�(cross)��ȥ��
DESC ;
}

void init()
{
//        add_action("do_cross", "cross");
}

int do_cross(string arg)
{
        object me;
        me = this_player();

        if (arg != "�ٲ�" || arg != "pubu") 
                return notify_fail("��Ҫ���Ķ�����\n");
        {
                write(HIY "������һ�������ٲ��ﴩȥ��\n" NOR);
                message("vision", HIY + me->name() + HIY "����һ��ͻȻ�����ˡ�\n" NOR, environment(me), ({me}) );
                me->move(__DIR__"mishi");
                message("vision", HIW + me->name() + HIW "ȫ��ʪ���ܵش��ٲ��ﴩ�˽�����\n" NOR, environment(me), ({me}) );
        }
        return 1;
}
