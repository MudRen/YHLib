inherit ROOM;

void create()
{
        set("short", "ũ��");
        set("long", @LONG
������һ��Сũ�ᣬ�Ҿߺ��¡��������˱Ƚϸ�ԣ��
LONG);
        set("exits", ([
                "west" : __DIR__"guangchang",
        ]));
        set("objects",([
                __DIR__"npc/woman" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
