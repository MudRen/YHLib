inherit ROOM;

void create()
{
	set("short","ҩ��");
	set("long",@LONG
����һ�����ص�ҩ�̣������ڴ�ͽֺ������ĵĽ��紦
��ͨ����������ƣ��ַ��Ƕ�˵���ҩ�̵�ҩ����ĺܡ���
ҩ���ϵļ��ٸ�С������ɢ��������һ��ŨŨ��ҩζ������
������Ϣ����˵��ҵ�����һ�ֺ����ܵ�ҩ�
LONG);
	set("exits", ([
	    	"north"  : __DIR__"taiheeast",
	]));
	setup();
	replace_program(ROOM);
}

