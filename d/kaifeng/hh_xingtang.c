inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�˴��˺컨���ܶ��ڵ��������ڣ��䱸��Ϊɭ�ϡ�ִ����
��ı��ǻ��еĵ�ʮ���ѽ��Σ��˳ơ�������ʯ˫Ӣ����
������˽���ĺ����������˹����ľ����ӵ����ĺ��ǣ���Ҳ��
����ץ�����̣����Ժ컨���ֵܣ��ᵽ�����ʱ�޲��Ȼ��
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"hh_hguangchang",
	]));
        set("objects", ([
                CLASS_D("honghua") + "/shi" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
