inherit ROOM;

void create()
{
	set("short", "��ʥ��");
        set("long", @long
��������̲���������������㻨��ԭ������ʥ�����ܶ�
�ǲ����ɽ����ס�˺��������������������������˼�������
�������ɽ�꣬��ǲ���Ӷ������ϣ��������ã������滨����
ǰ����ֲ��������ɽ�����������һ��������
long);

	set("exits", ([
		"north" : __DIR__"jingshenfeng",
		"down" :  __DIR__"fufengshan",
	]));
        
        set("outdoors", "kunlun");
        setup();
        replace_program(ROOM);
}
