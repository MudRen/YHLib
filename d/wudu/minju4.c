inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ͨ��ũ�ң�����û��ʲô�����İ��衣ǽ�߰ڷ���һ
Щũ�ߣ������а���һ�Ű��������峤�����ź��̴��������߳��š� 
LONG);

        set("exits", ([
                "south" : __DIR__"cun5",
        ]));
        set("objects", ([
                __DIR__"npc/cunzhang": 1,
        ]));

        setup();
        replace_program(ROOM);
}
