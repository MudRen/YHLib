inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ��СС����Ϣ�ң�ûʲô���������ߵ�����ֻ�����º�
����Ϣһ�¡���ͷ������С����õ�Ũ�衣
LONG);
        set("exits", ([
                "east" : __DIR__"yinghaoup",
                
        ]));
        setup();
        replace_program(ROOM);
}
