inherit ROOM;

void create()
{
	set("short","¥��");
	set("long",@LONG
�����ͨ����¥��ӭ��ի����¥�ݣ�����¥�ݸ�����ʮ
�༶�����������ʺ�ëձ��¥������վ��һЩ������ʿ��¥
�����ǹ����Ϣ�ĵط���
LONG);
	set("objects", ([
	   	CLASS_D("duan") + "/gao" : 1,
	]));
	set("exits", ([
	    	"up" : __DIR__"zoulang1",
	    	"south" : __DIR__"dating",
	]));
	setup();
	replace_program(ROOM);
}

