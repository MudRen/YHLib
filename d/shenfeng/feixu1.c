inherit ROOM;

void create()
{
	set("short", "�߲�����");
	set("long", @LONG
��Ȼ����ǰһƬ�տ�����ʱ����������ֻ����ɫ������Ī
����״��һ������ɽ�������𣬷�ǰһ���ŵĶ��Ƿ��ݡ�ǧ
�������ݶ�ԫʣ�ߣ����Ʋ�������ûһ����������������ģ��
�������ʣ��ɼ�������һ��ʮ�ַ��ٵĳ��С�
LONG);
        set("outdoors", "gaochang");

	set("exits", ([
  		"east" : __DIR__"shibi",
  		"west" : __DIR__"feixu2",
	]));

	setup();
	replace_program(ROOM);
}
