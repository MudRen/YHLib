inherit ROOM;

void create()
{
	set("short", "��ͽ�");
	set("long", @LONG
����Ե������������ֹ��ӣ������۴��αȣ�����������
����һƬ̫ƽ���־���·���������Ŵ���������һ̤������
����軨�����˱Ƕ�����
LONG);
	set("outdoors", "dali");
	set("exits", ([
	    	"north" : __DIR__"baiyiziguan",
	    	"south" : __DIR__"baiyiminju",
	    	"west"  : __DIR__"shizilukou",
	]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
