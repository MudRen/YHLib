inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
���������������ı����������ܷ��⼸�������ܣ�����
���������˵���ƽʱ�����õ��񽣡�
LONG);
	set("objects", ([
            	"/clone/weapon/zhujian" : 4,
            	"/clone/weapon/changbian" : 1
	]));
	set("exits", ([
	    	"south"  : __DIR__"chahua1",
	]));
	setup();
        replace_program(ROOM);
}
