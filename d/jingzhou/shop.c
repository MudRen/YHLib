inherit ROOM;

void create()
{
        set("short", "��԰");
	set("long", @LONG
�㿴�����ܷ������£�������һ�������˶����԰�ӣ���
����������ͻҳ���ʹ�˲��ɵ���Ȼ���ˡ�
LONG);
        set("outdoors", "jingzhou");
        set("exits", ([
	  	"south" : __DIR__"dongdajie2",
	]));
        set("objects", ([
                "/d/kaifeng/npc/qigai" : 1,
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 
