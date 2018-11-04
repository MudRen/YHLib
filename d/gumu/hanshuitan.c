
#include <ansi.h>
inherit BUILD_ROOM;

int do_qian(string arg);

void create()
{
        set("short", "��ˮ̶");
        set("long", @LONG
�����ǲݵصı�Ե������Ѿ���ϡ���ˣ���Ȼ��Щ�����
�ɹ�Ѱ��ʳ���Զ����һ���岨�����Ĵ�ˮ̶ (tan)��ˮ��
�壬��Լ���Լ���ˮ�׵Ĺ�ʯ��ᾣ�һ������ٿ�ش�ˮ���ι���
�ֲ�֪���㵽�Ŀ�ʯͷ�������ȥ�ˡ�����ӳ���£�ˮ�淺��
��һ����ɫ�ʺ磬����������������������
LONG
        );
        set("outdoors", "quanzhen");
        set("max_room", 3);
        set("exits", ([
                "northwest" : __DIR__"caodi2",
        ]));

        set("item_desc", ([
        "tan": HIW "\nһ�ں����ˮ̯����֪���ɲ�����Ǳ(qian)�µ���ˮ������ȥ��\n"NOR,
        ]) );

        setup();
}

void init()
{
        add_action("do_qian", "qian");
}


int do_qian(string arg)
{
        object me=this_player();

        if (! arg || arg != "tan" )
                return notify_fail("��Ҫ������Ǳˮ��\n");

        message_sort(HIG "$N����һԾ������ˮ̯֮�У���������"
                     "������ι���������һ�̣�ȴץ�˿ա�ͻȻ$N "
                     HIG "��ǰһ����һ�ɰ��������������$N" HIG 
                     "����һ�����ڡ�\n" NOR,this_player());

        me->move(__DIR__"mishi1");
        return 1;
}

