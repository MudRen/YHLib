
inherit ROOM;

void create()
{
        set("short", "�յ�");
        set("long", @LONG
��������ɽɽ������һ��յأ�����ƽ̹������һ��С·
ֱ��ɽ赶��ϣ�ͨ��������ɽ���塣�ϱߺ�������һ��Ƭ���֣�
ֻ���������������д�����������һ��ɽ·�����Ϻ�������һ
��С����
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "west"     : __DIR__"shulin5",
                "south"    : __DIR__"shulin4",
                "northup"  : __DIR__"shanlu1",
        ]));

        setup();
        replace_program(ROOM);
}
