
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�˶�ɽ·�������ͱڿ�������ģ��ر�������С���ʱ��
�ڱ߱�������ɽ赣�������������䵱ɽ�ﴵ��֮ʱ��������
��С�ģ���Ȼһʧ�㣬��Ҫ����������Ԩ�ˡ�������һ����
�Ŀյء���������һ����ҡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup"    : __DIR__"daxiaochang",
                "southdown"  : __DIR__"juyan",
        ]));

        setup();
        replace_program(ROOM);
}
