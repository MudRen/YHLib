inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ï�ܵ�ɭ�֡����ܶ���������ĳ��ݣ�һ����ɭ��
�������ա�Զ����ʱ����Ұ�޵ĺ��У���ʵ�ڲ��������������
LONG);
        set("outdoors", "motianya");
        set("exits", ([
                "east"  : __DIR__"mtroad4",
                "west"  : __FILE__,
                "north" : __FILE__,
                "south" : __FILE__,
        ]));
        set("objects", ([
                "/clone/quarry/zhu2" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
