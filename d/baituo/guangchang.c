inherit ROOM;

void create()
{
        set("short", "�㳡");
        set("long", @LONG
������һ�鲻С�Ĺ㳡���������ũ��ɹ�Ĺ��������
����ɽׯ�������м�Сũ�ᣬ�����п�˵أ��Ϸ���һ��С�š�
LONG);
        set("outdoors", "baituo");
        set("exits", ([
                "east"    : __DIR__"nongshe",
                "northup" : __DIR__"shijie",
                "west"    : __DIR__"shanlu",
                "south"   : __DIR__"bridge",
        ]));
        set("objects",([
                __DIR__"npc/kid" : 2,
        ]));
        setup();
        replace_program(ROOM);
}
