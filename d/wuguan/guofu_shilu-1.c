inherit ROOM;

void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
������һ��ʯ��·�ϣ���������������Ʒ��������в���
���������Ÿ����Ĺ��ߣ����Ǳ߹����������ǹ����Ĵ�����
LONG);
        set("no_fight", 1);
        set("exits", ([
              "east" : __DIR__"guofu_wupinfang",
              "west" : __DIR__"guofu_dating",
              "north" : __DIR__"guofu_xuetang",
              "south" : __DIR__"guofu_zhangfang",
        ]));
        set("outdoors", "xiangyang");
        setup();
        replace_program(ROOM);
}
