inherit ROOM;

void create()
{
        set("short", "��ʯ̲");
        set("long", @LONG
�����ʯ������·�������ߣ���С�ľ�Ҫˤ������������
��Ƭʯ̲�����ǳ������ߡ�
LONG);
        set("outdoors", "kunming");
        set("exits", ([
                "north" : __DIR__"road2", 
                "southwest" : __DIR__"road4",
                
        ]));

        setup();
        replace_program(ROOM);
}
