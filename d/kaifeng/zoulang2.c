inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������̵�һ�����ȣ�����ĵذ��뿪�������ߣ���ϴ��
�ܸɾ���ÿ��һ�ε��ȼ��϶��ο��˾��µķ�������������
�ϣ������ȥ���ǲ�԰���ϱߵĿյ���Ҳ���˼��òˡ�������
��С�񷿡�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"zoulang",
  		"east" : __DIR__"caidi",
  		"south" : __DIR__"caidi2",
  		"north" : __DIR__"caifang",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
