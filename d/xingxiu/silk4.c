inherit ROOM;

void create()
{
        set("short", "˿��֮·");
          set("long", @LONG
����һ����ԭ������֮����̵���������һ���޼ʵĴ�ɳ
Į����˵���ﳣ�е��˳�û��������ͨ��һƬ�����ɽ������
����ͨ����ԭ��·��·����һ��ʯ����
LONG);
        set("outdoors", "xiyu");
        set("exits", ([
                "east" : __DIR__"silk3",
		"west" : __DIR__"shamo1",
                "northwest" : __DIR__"shanjiao",
		"southwest" : "/d/xueshan/caoyuan" ,
        ]));
        setup();
        replace_program(ROOM);
}
