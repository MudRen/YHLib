inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�ϴ�����ǳ���ķ����ضΣ�һ�����ϣ�һ�ɵƺ���̣�
��Ϊ���֡�Ц�������������������������һƬ��������Ķ�
�䣬�㲻����Գ��������ʹ�ͣ������һ�������ݵĳ�����
����ɫ��ʱ��ʹ���Ŀ���������ʱ�˿�ֻ���������Ȼ������
��ɫ��Ϊһ�塣�����￴ȥ�������ϳǵĽ־���һƬ���֡���
�ֵĶ�������һ����ݣ�������ȥ��һ������԰�֡�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"shizilin",
		"west"      : __DIR__"jubaozhai",
		"north"     : __DIR__"baodaiqiao",
		"south"     : __DIR__"nandajie3",
	]));
	setup();
	replace_program(ROOM);
}

