inherit ROOM;

void create()
{
      set("short", "�����");
      set("long", @LONG
�����ǽ𶥻����������ǽӴ���ͼ������ĵط�����
�ڰ��ż������ӣ�����Χ���������ӡ�ǽ�����ż����ֻ���ǽ
��һ����ܣ����ϰ������顣��λ���������Ʒ����������
ǽ�ϵ��ֻ����ļ��ϵľ��顣����������ʮ����Ĺ�������
һλʦ̫�����йس��ҵ��¡�һ��ʮ�����Сʦ̫����æǰæ
���д����ˡ��ϱ����ȴ���(chuang)��
LONG);
      	set("objects", ([
           	CLASS_D("emei") + "/wenqing" : 1,
      	]));
      	set("item_desc", ([
          	"chuang" : "������Կ�����üɽ������ɽ����\n",
    	]));

	set("exits",([
        	"east"   : __DIR__"hcazhengdian", 
      	]));
      	setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me = this_player();

        if (! arg || arg != "chuang")
                return 0;

        message_vision("$N���˲�ע�⣬�������⡣\n", me);
        me->move(__DIR__"xiaoshulin1");
        message_vision("$N�ӻ�����������������\n", me);
        return 1;
}
