inherit ROOM;

void create()
{
        set("short", "���᷿");
        set("long", @LONG
������̫ү���﹩���˾�ס�ĵط�������ûʲô������ֻ
��һ�����Ӻͼ�����ʡ��ݽǵ��������һ��ѵ��·����м�
��Ѿ��û�������廨��
LONG);
        set("exits", ([
                "east" : __DIR__"huayuan",
                                 
        ]));

        set("objects", ([
	        __DIR__"npc/yahuan" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
