inherit ROOM;

void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
������һ��ʯ��·�ϣ���������涼��ϰ���ã���������
������������ģ������ǹ����Ŀ�����
LONG);
        set("no_fight", 1);
        set("exits", ([
               "east" : __DIR__"guofu_dating",
               "west" : __DIR__"guofu_shilu-4",
               "north" : __DIR__"guofu_xiwutang",
               "south" : __DIR__"guofu_xiwutang2",
        ]));
        set("outdoors", "xiangyang");
        setup();
        replace_program(ROOM);
}
