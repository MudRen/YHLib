inherit ROOM;

void create()
{
	set("short","���Ĺ㳡");
	set("long",@LONG
�������������ǵ����ģ���ɫʯ���̳ɵĴ�����ķ�
���ӡ��㳡�����Σ�һȦΧ�Ķ���С�������ˣ��Ϳ����ֵġ�
������������Ⱥ��Ҳ�ٲ��˼����ܽ���֮�ˣ�һЩ����ԭ��
��δ�ŵ�������һЩ���뽭��֮���˷ܲ��ѡ�
LONG);
	set("objects", ([
	   	__DIR__"npc/jianghuyiren": 1,
	]));
	set("outdoors", "dali");
	set("exits", ([
	    	"north"  : __DIR__"taihejiekou",
	    	"south"  : __DIR__"shizilukou",
	    	"east"   : __DIR__"taiheju",
	]));
	setup();
	replace_program(ROOM);
}

