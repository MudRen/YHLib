inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������ǵ���������ʮ������Ϊ������������������
ʿ�ŹǶ����������ÿ���а����ĵĺú����ⶼ��������һ
���һꡣ
LONG );
        set("exits", ([
                "west" : __DIR__"eastroad2",
        ]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

