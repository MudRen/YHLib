inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���߽�һƬ��ѹѹ�������֣����������֦��Ҷï������
�����������ա�������������Ҽ������������ڵ���������
�У��γ�һ������ɫ�Ĺ�����ɷ�Ǻÿ������������ţ���Ȼ��
���Լ�����ʧ����Ƭ�����У��Ҳ�����ȥ��·�ˡ�
LONG);
	set("exits", ([
  		"west"  : __DIR__"sslin-4",
  		"east"  : __FILE__,
  		"south" : __DIR__ "sslin-2",
  		"north" : __FILE__,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
