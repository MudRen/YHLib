inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
���ƽ̹�羵����ɳĮ�ϵ�ɳ�����ȫȻ��ͬ��ֻ��һƬ
ƽɳ������Զ����ֻ�������ӣ��������������˾�������
Ҳ������֮�У��پ���ǧ���ޣ�һ����С�쳣��
LONG);
        set("outdoors", "xiyu");
        set("exits", ([
  		"east" : __DIR__"caoyuan4",
   		"west"  : "/d/xingxiu/nanjiang1",
   		"south" : "/d/xingxiu/nanjiang2",
   		"southwest" : "/d/xingxiu/nanjiang1",
	]));

	setup();
	replace_program(ROOM);
}
