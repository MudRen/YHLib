
inherit ROOM;

void create()
{
        set("short", "ǰ��");
        set("long", @LONG
�����ǹ�Ĺ��ǰ����������ģ��㼸��ʲôҲ�����塣ȫ
���������м������������һ��ҹ���飬ӳ��������ƹ⡣��
��������˶���ʯ�����ɵģ������ƺ���д��һЩʲô��--��
��ôҲ��������ˡ�
LONG
        );

        set("exits", ([
                "south" : __DIR__"xiaoting",
                "north" : __DIR__"mumen",
        ]));

        setup();
        replace_program(ROOM);
}
