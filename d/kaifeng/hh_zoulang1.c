inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǻ컨���ܶ��ڵ�һ��ľ�Ƶ����ȣ����������ǹ⻬
�������ȱ�������һ����Ⱦ���㲻ʱ�ܹ����������컨��Ļ�
�ڻ��ǵ����ڴ��߶���æµ����ͣ��
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"hh_qianting",
  		"south" : __DIR__"hh_guangchang",
	]));
        setup();
        replace_program(ROOM);
}
