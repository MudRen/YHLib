inherit ROOM;

string* names = ({
        __DIR__"obj/mala-doufu",
        __DIR__"obj/bocai-fentiao",
        __DIR__"obj/shanhu-baicai",
        __DIR__"obj/liuli-qiezi",
});

void create()
{
      set("short", "ի��");
      set("long", @LONG
������Ƕ��һ����ֵ�ի�á�ի��������˳����Ĳ�����
���ʣ���λСʦ̫������æµ�Ų�����ի�����ϰ��˼��趹����
����������Լ���Ѽ����ζ��ʳ��ի�ú�����һ����ͨ������
�ִ���䣬���ߵ�����ͨ��㳡��
LONG);
      set("exits", ([
          "south" : __DIR__"chuwujian", 
          "north" : __DIR__"hcaeast2", 
      ]));

      set("objects",([
           __DIR__"obj/qingshui-hulu" : 1,
           names[random(sizeof(names))]: 1,
           names[random(sizeof(names))]: 1,
           names[random(sizeof(names))]: 1,
      ]));
      setup();
      replace_program(ROOM);
}
