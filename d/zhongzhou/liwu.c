inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
�������������ݣ�������å������ڶ�Ǯ�������и�С
�ţ������Ϊ�����·�����ʱ��Ľ���ͨ����
LONG);
        set("exits", ([
                "out" : __DIR__"eba",
                "south" : __DIR__"hutong2",     
        ]));

        setup();
        replace_program(ROOM);
}
