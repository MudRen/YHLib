inherit ROOM;

void create()
{
        set("short", "�䳡");
        set("long", @LONG
�����Ǵ����µĴ����䳡�����źö�ľ׮��ɳ����ɮ����
�ճ����ڴ˿̿�ϰ�䡣�����ߴ������������䳡���ǹ㳡����
���и�С�ⷿ���ϱ�һ��Ƭ�����أ�����ѩɽ�������ڵļ�̳��
LONG );
        set("outdoors", "xueshan");
        set("exits", ([
                "east" : __DIR__"chang2",
                "west" : __DIR__"kufang",
                "north" : __DIR__"chang3",
                "south" : __DIR__"jitan",
        ]));

        set("objects", ([
                __DIR__"npc/x_lama" : 1,
        ]));

        setup();

        replace_program(ROOM);
}
