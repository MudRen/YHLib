inherit ROOM;

void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
������һ��ʯ��·�ϣ�һֱͨ���Ժ��·������Щ��ͨ��
���ݣ����ϵ�С�񣬲�ͣ�Ľ��š�
LONG);
        set("no_fight", 1);
        set("exits", ([
               "north" : __DIR__"guofu_houyuan",
               "south" : __DIR__"guofu_shilu-4",
        ]));
        set("objects", ([
           	__DIR__"npc/puren1" : 1,
        ]));
        set("outdoors", "xiangyang");
        setup();
        replace_program(ROOM);
}
