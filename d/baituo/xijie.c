inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������С������֡������и��Ƶ꣬��ǰ�����Ÿ߸ߵ���
�ˣ�һ���಼����ӭ��Ʈ�����ӡ�����ɫ�ľ��֡�
LONG);
        set("outdoors", "baituo");
        set("exits", ([
                "west"  : __DIR__"bridge",
                "east"  : __DIR__"dongjie",
                "south" : __DIR__"jiudian",
        ]));
        set("objects", ([
                __DIR__"npc/man" : 1,
                __DIR__"npc/snaker"  :1,
        ]));
        setup();
        replace_program(ROOM);
}
