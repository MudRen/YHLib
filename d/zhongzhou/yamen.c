inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
��������������ţ����Ե��ྲ����������������е���
�����������ߵ���������Ŀ����㣬����Ҫ״����ˡ�
LONG);
        set("outdoors", "zhongzhou");
        set("exits", ([
                "east" : __DIR__"wendingbei3",
                "west" : __DIR__"zoulang",
                
        ]));

        set("objects", ([
	        __DIR__"npc/yayi" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
