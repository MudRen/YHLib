inherit ROOM;

void create()
{
        set("short", "��ɽɽ·");
        set("long", @LONG
��������ɽ��´��ɽ���ɽ�ϴ����������ɪɪ������·
����һƬ��Ҷ�֡�������ȥ������ңң�ɼ���
LONG );
        set("exits", ([
            	"westup" : __DIR__"tianroad6",
            	"eastdown" : __DIR__"tianroad4",
        ]));

        if (random(10) > 8)
        	set("objects", ([
                	__DIR__"npc/caiyaoren" : 1, 
        	]));

        set("outdoors", "xingxiu");
        setup();
        replace_program(ROOM);
}

