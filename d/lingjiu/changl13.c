inherit ROOM;

void create()
{
  	set("short", "����");
  	set("long", @LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ
�Ƴɣ����������һЩ������ͼ�����������ɣ�����ʤ�ա���
�岻֪����ʲô�������ģ��������������Ϣ����ֻ�е�����
����ģ��ǳ��������������ͨ�����ɵ��������������ҡ�
LONG);
  	set("exits",([
      		"east" : __DIR__"changl10",
      		"west" : __DIR__"xuanbing",
  	]));
        set("objects",([
                CLASS_D("lingjiu") + "/cheng" : 1,
        ]));
  	set("no_clean_up", 0);
  	setup();
  	replace_program(ROOM);
}
