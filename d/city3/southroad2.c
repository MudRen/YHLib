inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�������ڳɶ������ϴ���ϣ�����һ���������Ĵ�·ֱ
���������졣·�����������������ò����֡�һЩС��С����
��������ЩС���������������ţ����ߴ�������ᶽ�֣��㿴
��֪��Ϊɶ���ᰲ���ˡ�
LONG);
        set("outdoors", "chengdu");
	set("exits", ([
	    	"north"  : __DIR__"tiduroad",
	    	"south"  : __DIR__"southgate",
	    	"east"   : __DIR__"southroad1",
	    	"west"   : __DIR__"southroad3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
